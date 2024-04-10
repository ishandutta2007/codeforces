#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int t;
int a, b, c, d;
char seq[500111];
vector< pair<char, int> > chunks;
int n;

int have[100];
int cnt[100];

vector<int> gChunks[100];

int main()
{
    int i, j;
    int test;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        scanf("%s", seq+1);
        n = strlen(seq+1);

        have['A'] = a;
        have['B'] = b;

        cnt['A'] = 0;
        cnt['B'] = 0;
        for (i=1;i<=n;i++)
        {
            cnt[ seq[i] ]++;
        }
        if (cnt['A'] != a + c + d || cnt['B'] != b + c + d)
        {
            printf("NO\n");
            continue;
        }

        chunks.clear();
        chunks.push_back(make_pair(seq[1], 1));
        for (i=2;i<=n;i++)
        {
            //printf("See %c\n", seq[i]);

            if (seq[i] != seq[i - 1])
            {
                //printf("Extend prev\n");
                chunks.back().second++;
            }
            else
            {
                /// Same as beginning
                if (seq[i] == chunks.back().first)
                {
                    have[ seq[i] ]--;
                }

                chunks.push_back(make_pair(seq[i], 1));
                //printf("New chunk with %c\n", seq[i]);
            }
        }

        if (have['A'] < 0 || have['B'] < 0)
        {
            printf("NO\n");
            continue;
        }

        gChunks['A'].clear();
        gChunks['B'].clear();
        for (i=0;i<chunks.size();i++)
        {
            //printf("%c chunk of size %d\n", chunks[i].first, chunks[i].second);
            gChunks[ chunks[i].first ].push_back(chunks[i].second);
        }

        sort(gChunks['A'].begin(), gChunks['A'].end());

        sort(gChunks['B'].begin(), gChunks['B'].end());
        reverse(gChunks['B'].begin(), gChunks['B'].end());

        for (i=0;i<gChunks['A'].size();i++)
        {
            if (gChunks['A'][i] % 2 == 1)
                continue;

            int abGain = gChunks['A'][i] / 2;
            int baGain = (gChunks['A'][i] - 1) / 2;

            //printf("A chunk of size %d\n", gChunks['A'][i]);
            //printf("Ganins AB %d ; BA %d\n", abGain, baGain);

            if (c > 0 && c >= abGain)
            {
                c -= abGain;
            }
            else if (c == 0)
            {
                d -= baGain;
            }
            else
            {
                int baLeftover = (gChunks['A'][i] - c * 2 - 1) / 2;
                c = 0;
                d -= baLeftover;
            }

            //printf("c=%d; d=%d\n", c, d);
        }

        /// Balanced
        for (i=0;i<gChunks['A'].size();i++)
        {
            if (gChunks['A'][i] % 2 == 0)
                continue;

            int gains = gChunks['A'][i] / 2;
            gChunks['A'][i] = 0;
            if (c > 0 && c >= gains)
            {
                c -= gains;
            }
            else
            {
                d -= (gains - c);
                c = 0;
            }
        }

        for (i=0;i<gChunks['B'].size();i++)
        {
            if (gChunks['B'][i] % 2 == 0)
                continue;

            int gains = gChunks['B'][i] / 2;
            gChunks['B'][i] = 0;
            if (c > 0 && c >= gains)
            {
                c -= gains;
            }
            else
            {
                d -= (gains - c);
                c = 0;
            }
        }
        ///

        ///Pass 1 - fully use evens
        for (i=0;i<gChunks['B'].size();i++)
        {
            int abGain = (gChunks['B'][i] - 1) / 2;
            int baGain = gChunks['B'][i] / 2;

            //printf("B chunk of size %d\n", gChunks['B'][i]);
            //printf("Ganins AB %d ; BA %d\n", abGain, baGain);

            if (c > 0 && c >= abGain)
            {
                c -= abGain;
            }
            else if (c == 0)
            {
                d -= baGain;
            }
            else
            {
                int baLeftover = (gChunks['B'][i] - c * 2 - 2) / 2;
                c = 0;
                d -= baLeftover;
            }

            //printf("c=%d; d=%d\n", c, d);
        }

        if (c > 0 || d > 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    return 0;
}