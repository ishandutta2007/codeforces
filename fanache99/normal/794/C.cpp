#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

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

long long ReadLL() {
    long long answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 300000;
const int SIGMA = 26;

char a[1 + MAXN], b[1 + MAXN], answer[1 + MAXN];
deque<char> da, db;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s%s", a, b);
    int n = strlen(a);
    sort(a, a + n);
    sort(b, b + n);
    reverse(b, b + n);
    for (int i = 0; i < (n + 1) / 2; i++)
        da.push_back(a[i]);
    for (int i = 0; i < n / 2; i++)
        db.push_back(b[i]);
    bool how = false;
    int left = 0, right = n + 1;
    for (int i = 1; i <= n; i++)
        if (i % 2) {
            if (!db.empty() && da[0] >= db[0])
                how = true;
            if (how) {
                right--;
                answer[right] = da.back();
                da.pop_back();
            }
            else {
                left++;
                answer[left] = da[0];
                da.pop_front();
            }
        }
        else {
            if (!da.empty() && da[0] >= db[0])
                how = true;
            if (how) {
                right--;
                answer[right] = db.back();
                db.pop_back();
            }
            else {
                left++;
                answer[left] = db[0];
                db.pop_front();
            }
        }
    printf("%s\n", answer + 1);
    return 0;
}