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
#include <cassert>

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
    int answer = 0,sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        ch = Advance();
        sign = -1;
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

bool Vowel(char before) {
    if (before == 'a' || before == 'e' || before == 'i' || before == 'o' || before == 'u' || before == 'y')
        return true;
    return false;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    char before = 'z';
    for (int i = 1; i <= n; i++) {
        char ch = ReadCh();
        if (Vowel(before) && Vowel(ch))
            continue;
        else {
            printf("%c", ch);
            before = ch;
        }
    }
    return 0;
}