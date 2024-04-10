//#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>

using namespace std;

const int SIZE = 1 << 17;
int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

vector<int> v;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n % 4 == 0 || n % 4 == 3)
        printf("0\n");
    else
        printf("1\n");
    for (int i = n - 4 + 1; i >= 1; i -= 4) {
        v.push_back(i + 3);
        v.push_back(i);
    }
    if (n % 4 == 2)
        v.push_back(1);
    if (n % 4 == 3)
        v.push_back(3);
    printf("%d ", v.size());
    for (auto &it : v)
        printf("%d ", it);
    return 0;
}