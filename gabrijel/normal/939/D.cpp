#include <bits/stdc++.h>
using namespace std;

int n, br = 0;
string s1, s2;
vector <pair <char, char> > rj;
vector <vector <int> > graf;
vector <int> vi;
int rod [100];
bool bio [30];

int nadi (int cv)
{
    if (rod [cv] == cv) return cv;
    return rod [cv] = nadi (rod [cv]);
}

inline void spoji (int prvi, int drugi)
{
    rod [nadi (prvi)] = nadi(drugi);
}

void rek (int tko)
{
    if (bio [tko]) return;
    bio [tko] = 1;
    for (int j = 0; j < graf [tko].size(); j++)
    {
        if (bio [graf [tko] [j]]) continue;
        rj.push_back(make_pair(tko + 'a', graf [tko] [j] + 'a'));
        rek (graf [tko] [j]);
    }
    return;
}

int main()
{
    for (int i = 0; i < 30; i++) rod [i] = i;
    graf.insert(graf.begin(), 30, vi);
    scanf("%d", &n);
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        if (s1 [i] != s2 [i] && nadi(s1 [i] - 'a') != nadi (s2 [i] - 'a'))
        {
            //cout << s1 [i] - 'a' << " " << s2 [i] - 'a' << endl;
            br++;
            graf [s1 [i] - 'a'].push_back(s2 [i] - 'a');
            graf [s2 [i] - 'a'].push_back(s1 [i] - 'a');
            spoji(s1 [i] - 'a', s2 [i] - 'a');
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (graf [i].size() < 2) {rek(i);}
    }
    printf("%d\n", br);
    for (int i = 0; i < rj.size(); i++)
    {
        printf("%c %c\n", rj [i].first, rj [i].second);
    }
    return 0;
}