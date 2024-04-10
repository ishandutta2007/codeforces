#include <bits/stdc++.h>
using namespace std;

int k, duljina, b0 = 0, b1 = 0, ispred = 0;
char s [200100];
bool bio [200100];
bool z = 0;
vector <pair <int, int> > nule;
vector <pair <int, int> > jedinice;
vector <int> vi;
vector <vector <int> > rj;

int main()
{
    scanf("%s", s);
    duljina = strlen(s);
    for (int i = 0; i < duljina; i++)
    {
        if (s [i] == '0') b0++;
        else b1++;
    }
    for (int i = 0; i < duljina; i++)
    {
        if (s [i] == '0') ispred++;
        else ispred--;
        if (ispred < 0)
        {
            printf("-1\n");
            return 0;
        }
    }
    ispred = 0;
    for (int i = duljina - 1; i >= 0; i--)
    {
        if (s [i] == '0') ispred++;
        else ispred--;
        if (ispred < 0)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", b0 - b1);
    rj.insert(rj.begin(), b0 - b1, vi);
    int ind = 0;
    for (int i = 0; i < duljina; i++)
    {
        if (s [i] == '0')
        {
            if (jedinice.size())
            {
                nule.push_back(make_pair(i, jedinice.back().second));
                rj [nule.back().second].push_back(i);
                jedinice.pop_back();
            }
            else
            {
                nule.push_back(make_pair(i, ind));
                rj [ind].push_back(i);
                ind++;
            }
        }
        else
        {
            jedinice.push_back(make_pair(i, nule.back().second));
            rj [jedinice.back().second].push_back(i);
            nule.pop_back();
        }
    }
    for (int i = 0; i < rj.size(); i++)
    {
        printf("%d ", rj [i].size());
        for (int j = 0; j < rj [i].size(); j++)
        {
            printf("%d ", rj [i] [j] + 1);
        }
        printf("\n");
    }
    return 0;
}