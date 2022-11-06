#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

enum op_t { COPY, AND, OR, XOR };

struct var_t {
  op_t op;
  int opa, opb;
  string value;
};

map<string, int> varid;

var_t read_var(int depth) {
  static char name_buffer[10+1];
  scanf("%s :=", name_buffer);
  string name(name_buffer);
  int id = varid.size();
  varid[name] = id;

  static char opa[1000+1], opb[10+1], optype[3+1];
  scanf("%s", opa);
  if (opa[0] == '0' || opa[0] == '1') {
    return {COPY, -1, -1, string(opa)};
  } else {
    scanf("%s %s", optype, opb);
    int opaid = -1, opbid = -1;
    if (opa[0] == '?') opaid = -1;
    else opaid = varid[string(opa)];
    if (opb[0] == '?') opbid = -1;
    else opbid = varid[string(opb)];
    op_t op;
    if (string(optype) == "AND") op = AND;
    if (string(optype) == "OR") op = OR;
    if (string(optype) == "XOR") op = XOR;
    return {op, opaid, opbid, string()};
  }
}

vector<int> bitvalues;

int get_one_count(int pos, vector<var_t> &vars, int newbit) {
  int result = 0;
  for (int i = 0; i < (int)vars.size(); ++i) {
    var_t &var = vars[i];
    if (var.op == COPY) bitvalues[i] = var.value[pos] - '0';
    else {
      int opa;
      if (var.opa == -1) opa = newbit;
      else opa = bitvalues[var.opa];
      int opb;
      if (var.opb == -1) opb = newbit;
      else opb = bitvalues[var.opb];
      int res;
      if (var.op == AND) res = opa & opb;
      else if (var.op == OR) res = opa | opb;
      else res = opa ^ opb;
      bitvalues[i] = res;
      result += res;
    }
  }
  return result;
}

int main() {
  int nvar, depth;
  scanf("%d %d", &nvar, &depth);
  vector<var_t> vars(nvar);

  for (int i = 0; i < nvar; ++i) {
    vars[i] = read_var(depth);
  }

  bitvalues.resize(nvar);
  string result_min(depth, '0'), result_max(depth, '0');
  for (int l = 0; l < depth; ++l) {
    int count0 = get_one_count(l, vars, 0);
    int count1 = get_one_count(l, vars, 1);
    if (count0 <= count1) result_min[l] = '0';
    else result_min[l] = '1';
    if (count0 >= count1) result_max[l] = '0';
    else result_max[l] = '1';
  }

  printf("%s\n%s\n", result_min.c_str(), result_max.c_str());

  return 0;
}