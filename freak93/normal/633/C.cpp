#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Trie {
    Trie(int _value = -1) {
        memset(next, 0, sizeof(next));
        value = _value;
    }
    Trie* next[26];
    int value;

    void add(const string& word, int v) {
        Trie* current = this;
        for (auto it = word.rbegin(); it != word.rend(); ++it) {
            char c = *it;
            if (c >= 'A' && c <= 'Z')
                c = c - 'A' + 'a';

            if (current->next[c - 'a'] == 0)
                current->next[c - 'a'] = new Trie();
            current = current->next[c - 'a'];
        }
        current->value = v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;
    string S; cin >> S;

    Trie *T = new Trie();
    int M; cin >> M;
    vector<string> words(M);
    for (int i = 0; i < M; ++i) {
        cin >> words[i];
        T->add(words[i], i);
    }

    vector<int> solution(N + 1, -1);
    solution[0] = 0;
    S = " " + S;
    for (int i = 0; i < N; ++i) {
        if (solution[i] != -1) {
            Trie *start = T;
            for (int j = i + 1; j <= N; ++j) {
                if (start->next[S[j] - 'a'] == 0)
                    break;
                start = start->next[S[j] - 'a'];
                if (start->value != -1)
                    solution[j] = start->value;
            }
        }
    }

    vector<string> answer;
    for (int i = N; i != 0; i -= words[solution[i]].size())
        answer.push_back(words[solution[i]]);
    reverse(answer.begin(), answer.end());
    for (auto &word : answer)
        cout << word << " ";
    cout << "\n";
}