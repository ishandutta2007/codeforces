#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

#ifndef ONLINE_JUDGE

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);
FILE *file_in = fopen("input.txt", "rt");
FILE *file_out = fopen("output.txt", "wt");

#else

#define fin cin
#define fout cout
#define file_in stdin
#define file_out stdout

#endif

struct TTeam {
    string name;
    int score;
    int goals, miss;
    TTeam()
        : name("")
        , score(0)
        , goals(0)
        , miss(0)
    {
    }

    bool operator<(const TTeam &team) const {
        if (score != team.score) {
            return score > team.score;
        }
        if (goals - miss != team.goals - team.miss) {
            return goals - miss > team.goals - team.miss;
        }
        return goals > team.goals;
    }
};

pair< string, string > split(string &s, char c) {
    pair< string, string > ans;
    for (int j = 0; j < s.size(); ++j) {
        if (s[j] == c) {
            return make_pair(s.substr(0, j), s.substr(j + 1, s.size() - j - 1));
        }
    }
}

int strToInt(string &s) {
    int n = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        n = 10 * n + s[i] - '0';
    }
    return n;
}

int main() {
    int n;
    fin >> n;
    vector< TTeam > teams(n);
    for (int i = 0; i < n; ++i) {
        fin >> teams[i].name;
    }
    for (int i = 0; i < n * (n - 1) / 2; ++i) {
        string names;
        fin >> names;
        pair< string, string > namessplit = split(names, '-');
        int firstTeam, secondTeam;
        for (int i = 0; i < n; ++i) {
            if (teams[i].name == namessplit.first) {
                firstTeam = i;
            }
            if (teams[i].name == namessplit.second) {
                secondTeam = i;
            }
        }
        string result;
        fin >> result;
        pair< string, string > scores = split(result, ':');
        int firstScore = strToInt(scores.first);
        int secondScore = strToInt(scores.second);
        if (firstScore > secondScore) {
            teams[firstTeam].score += 3;
        } else {
            if (secondScore > firstScore) {
                teams[secondTeam].score += 3;
            } else {
                ++teams[firstTeam].score;
                ++teams[secondTeam].score;
            }
        }
        teams[firstTeam].goals += firstScore;
        teams[firstTeam].miss += secondScore;
        teams[secondTeam].goals += secondScore;
        teams[secondTeam].miss += firstScore;
    }

    sort(teams.begin(), teams.end());
    vector< string > winners(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        winners[i] = teams[i].name;
    }
    sort(winners.begin(), winners.end());
    for (int i = 0; i < n / 2; ++i) {
        fout << winners[i] << '\n';
    }

    return 0;
}