#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

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

const int MAXN = 1000000;

char s[1 + MAXN];
vector<int> words;

bool Check(int width, int lines) {
    int used = 1, length = 0;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] > width)
            return false;
        if (length + words[i] <= width)
            length += words[i];
        else {
            length = words[i];
            used++;
        }
    }
    return used <= lines;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int k;
    scanf("%d\n", &k);
    gets(s + 1);
    int n = strlen(s + 1), length = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == '-' || s[i] == ' ') {
            words.push_back(length + 1);
            length = 0;
        }
        else
            length++;
    words.push_back(length);
    int left = 1, right = n, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (Check(middle, k)) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    printf("%d\n", answer);
    return 0;
}