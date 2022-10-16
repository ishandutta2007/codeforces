//#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000000;

char s[1 + MAXN];

struct Element {
    string s;
    int depth;
    int moment;

    Element() {}

    Element(string _s, int _depth, int _moment):
        s(_s), depth(_depth), moment(_moment) {}

    bool operator < (const Element &other) const {
        if (depth != other.depth)
            return depth < other.depth;
        return moment < other.moment;
    }
};

vector<Element> words;
vector<int> Stack;

bool IsLetter(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return true;
    return false;
}

bool IsDigit(char ch) {
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

int main() {
    cin >> s + 1;
    int n = strlen(s + 1), answer = 0;
    Stack.push_back(n);
    for (int i = 1; i <= n;) {
        string temp;
        int j = i;
        while (j <= n && IsLetter(s[j])) {
            temp.push_back(s[j]);
            j++;
        }
        j++;
        int sons = 0;
        while (j <= n && IsDigit(s[j])) {
            sons = sons * 10 + s[j] - '0';
            j++;
        }
        j++;
        answer = max(answer, (int)  Stack.size());
        words.push_back(Element(temp, Stack.size(), i));
        Stack.back()--;
        if (sons)
            Stack.push_back(sons);
        else
            while (!Stack.back())
                Stack.pop_back();
        i = j;
    }
    sort(words.begin(), words.end());
    cout << answer << "\n";
    for (int i = 0, j; i < words.size(); i = j) {
        j = i;
        while (j < words.size() && words[i].depth == words[j].depth) {
            cout << words[j].s << " ";
            j++;
        }
        cout << "\n";
    }
    return 0;
}