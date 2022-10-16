#include <iostream>
//#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>
#include <cstring>

using namespace std;

int main() {
    //ifstream cin("tema.in");
    //ofstream cout("tema.out");
    string a, b, answer;
    answer.resize(1);
    answer[0] = 'z' + 1;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++) {
            string now = a.substr(0, i + 1) + b.substr(0, j + 1);
            answer = min(answer, now);
        }
    cout << answer << "\n";
    return 0;
}