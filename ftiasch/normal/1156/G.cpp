#line 1 "sol.cpp"
#include <bits/stdc++.h>

struct Statement {
  char op;
  std::string lhs, rhs[2];
};

using Var = std::string;

using Composition = std::tuple<char, int, int>;

struct ValDesc {
  Var var;
  Composition how;
  bool computed;
};

int main() {
  std::ios::sync_with_stdio(false);
  int m;
  std::cin >> m;
  std::vector<Statement> statements(m);
  std::string buffer;
  for (int i = 0; i < m; ++i) {
    std::cin >> buffer;
    auto eq_index =
        std::find(buffer.begin(), buffer.end(), '=') - buffer.begin();
    auto op_index = std::find_if(buffer.begin(), buffer.end(),
                                 [&](char token) {
                                   return token == '$' || token == '^' ||
                                          token == '#' || token == '&';
                                 }) -
                    buffer.begin();
    auto &s = statements[i];
    s.lhs = buffer.substr(0, eq_index);
    if (op_index == buffer.size()) {
      s.op = '=';
      s.rhs[0] = buffer.substr(eq_index + 1, buffer.size() - (eq_index + 1));
    } else {
      s.op = buffer[op_index];
      s.rhs[0] = buffer.substr(eq_index + 1, op_index - (eq_index + 1));
      s.rhs[1] = buffer.substr(op_index + 1, buffer.size() - (op_index + 1));
    }
  }
  std::set<Var> reserved_vars;
  std::vector<ValDesc> vals;
  std::map<Var, int> valmap;
  auto reserve = [&](const Var &var) {
    auto [iterator, is_new] = valmap.emplace(var, vals.size());
    if (is_new) {
      reserved_vars.insert(var);
      vals.push_back(ValDesc{var, Composition{'\0', -1, -1}, true});
    }
  };
  for (const auto &s : statements) {
    reserve(s.lhs);
    reserve(s.rhs[0]);
    if (s.op != '=') {
      reserve(s.rhs[1]);
    }
  }
  reserve("res");
  int res0 = valmap["res"];
  std::map<Composition, int> composition;
  auto compose = [&](char op, int a, int b) {
    auto [iterator, is_new] =
        composition.emplace(Composition{op, a, b}, vals.size());
    if (is_new) {
      static char buffer[5];
      int count = -1;
      do {
        count++;
        buffer[0] = 'a' + (count / 1'000);
        sprintf(buffer + 1, "%d", count % 1'000);
      } while (!reserved_vars.insert(buffer).second);
      vals.push_back(ValDesc{buffer, Composition{op, a, b}, false});
    }
    return iterator->second;
  };
  for (const auto &s : statements) {
    if (s.op == '=') {
      valmap[s.lhs] = valmap[s.rhs[0]];
    } else {
      valmap[s.lhs] = compose(s.op, valmap[s.rhs[0]], valmap[s.rhs[1]]);
    }
  }
  auto res1 = valmap["res"];
  if (res1 == res0) {
    puts("0");
  } else if (vals[res1].computed) {
    printf("1\nres=%s\n", vals[res1].var.c_str());
  } else {
    vals[res1].var = "res";
    std::vector<std::string> program;
    std::function<void(int)> compute = [&](int id) {
      ValDesc &val = vals[id];
      if (!val.computed) {
        val.computed = true;
        auto [op, a, b] = val.how;
        compute(a);
        compute(b);
        program.push_back(val.var + "=" + vals[a].var + op + vals[b].var);
      }
    };
    compute(res1);
    printf("%d\n", static_cast<int>(program.size()));
    for (const auto& line : program) {
      puts(line.c_str());
    }
  }
}