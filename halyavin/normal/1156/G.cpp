#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>
#include <set>
#include <map>

std::array<char, 4> ops = {'$', '^', '#', '&'};

struct State {
    int op;
    int left;
    int right;

    bool operator<(const State &other) const {
        if (op != other.op) {
            return op < other.op;
        }
        if (left != other.left) {
            return left < other.left;
        }
        if (right != other.right) {
            return right < other.right;
        }
        return false;
    }

    bool operator==(const State &other) const {
        return op == other.op && left == other.left && right == other.right;
    }

    bool operator!=(const State &other) const {
        return !(*this == other);
    }
};

struct Solution {
    int n;
    std::vector<std::string> names;
    std::vector<int> varIdxStates;
    std::map<State, int> stateIdx;
    std::vector<State> states;
    std::vector<std::string> auxNames;
    std::vector<std::string> ans;
    std::map<int, int> stateToName;

    int getState(State &state) {
        auto it = stateIdx.find(state);
        if (it != stateIdx.end()) {
            return it->second;
        }
        int res = states.size();
        stateIdx[state] = res;
        states.push_back(state);
        return res;
    }

    int getName(std::string &name) {
        for (size_t i = 0; i < names.size(); i++) {
            if (names[i] == name) {
                return i;
            }
        }
        int res = names.size();
        names.push_back(name);
        State var{-1, res, 0};
        varIdxStates.push_back(getState(var));
        return res;
    }

    void genAuxNames() {
        auxNames.clear();
        std::set<std::string> namesSet(names.begin(), names.end());
        for (char s = 'a'; s <= 'z'; s++) {
            for (int i = 0; i < 1000; i++) {
                std::string name;
                name.push_back(s);
                int j = i;
                for (int k = 0; k < 3; k++) {
                    name.push_back((j % 10) + '0');
                    j /= 10;
                }
                std::reverse(name.begin() + 1, name.end());
                if (namesSet.count(name) == 0) {
                    auxNames.push_back(name);
                }
            }
        }
    }

    std::string rec(int state, bool root) {
        State s = states[state];
        if (s.op == -1) {
            return names[s.left];
        }
        auto it = stateToName.find(state);
        if (it != stateToName.end()) {
            return auxNames[it->second];
        }
        std::string varLeft = rec(s.left, false);
        std::string varRight = rec(s.right, false);
        std::string our;
        int ourIdx;
        if (root) {
            our = "res";
            ourIdx = -1;
        } else {
            ourIdx = stateToName.size();
            our = auxNames[ourIdx];
        }
        std::string op(our);
        op.push_back('=');
        op.append(varLeft);
        op.push_back(ops[s.op]);
        op.append(varRight);
        ans.push_back(op);
        stateToName[state] = ourIdx;
        return our;
    }

    void run(std::istream &in, std::ostream &out) {
        in >> n;
        names.clear();
        varIdxStates.clear();
        stateIdx.clear();
        states.clear();
        for (int i = 0; i < n; i++) {
            std::string line;
            in >> line;
            int pos = line.find('=');
            std::string var = line.substr(0, pos);
            std::string expr = line.substr(pos + 1);
            int op = -1;
            std::string left, right;
            for (int j = 0; j < ops.size(); j++) {
                size_t opPos = expr.find(ops[j]);
                if (opPos != std::string::npos) {
                    op = j;
                    left = expr.substr(0, opPos);
                    right = expr.substr(opPos + 1);
                    break;
                }
            }
            int varIdx = getName(var);
            if (op == -1) {
                int otherIdx = getName(expr);
                varIdxStates[varIdx] = varIdxStates[otherIdx];
            } else {
                int leftIdx = getName(left);
                int rightIdx = getName(right);
                State state{op, varIdxStates[leftIdx], varIdxStates[rightIdx]};
                varIdxStates[varIdx] = getState(state);
            }
        }
        int idxRes = -1;
        for (int i = 0; i < names.size(); i++) {
            if (names[i] == "res") {
                idxRes = i;
                break;
            }
        }
        if (idxRes == -1) {
            out << "0\n";
            return;
        }
        int resState = varIdxStates[idxRes];
        genAuxNames();
        ans.clear();
        stateToName.clear();
        std::string name = rec(resState, true);
        if (name != "res") {
            out << ans.size() + 1 << "\n";
        } else {
            out << ans.size() << "\n";
        }
        for (int i = 0; i < ans.size(); i++) {
            out << ans[i] << "\n";
        }
        if (name != "res") {
            out << "res=" << name << "\n";
        }
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution().run(std::cin, std::cout);
    return 0;
}