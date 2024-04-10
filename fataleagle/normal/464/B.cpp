#include <bits/stdc++.h>

using namespace std;

int pts[8][3];
vector<long long> len[2];

inline long long dist(int i, int j)
{
    long long dx=pts[i][0]-pts[j][0];
    long long dy=pts[i][1]-pts[j][1];
    long long dz=pts[i][2]-pts[j][2];
    return dx*dx+dy*dy+dz*dz;
}

inline void CHK()
{
    len[0].clear();
    for(int j=1; j<8; j++)
        len[0].push_back(dist(0, j));
    sort(len[0].begin(), len[0].end());
    #define check(b) if(!(b)) return
    #define L len[0]
    check(L[0]);
    check(L[0]==L[1]);
    check(L[0]==L[2]);
    check(2*L[0]==L[3]);
    check(2*L[0]==L[4]);
    check(2*L[0]==L[5]);
    check(3*L[0]==L[6]);
    for(int i=1; i<8; i++)
    {
        len[1].clear();
        for(int j=0; j<8; j++)
            if(i!=j)
                len[1].push_back(dist(i, j));
        sort(len[1].begin(), len[1].end());
        if(len[0]!=len[1])
            return;
    }
    printf("YES\n");
    for(int i=0; i<8; i++)
        for(int j=0; j<3; j++)
            printf("%d%c", pts[i][j], j==2?'\n':' ');
    exit(0);
}

void rec(int pos)
{
    if(pos==8)
        CHK();
    else
    {
        do
        {
            rec(pos+1);
        }
        while(next_permutation(pts[pos], pts[pos]+3));
        sort(pts[pos], pts[pos]+3);
    }
}

int main()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<3; j++)
            cin>>pts[i][j];
        sort(pts[i], pts[i]+3);
    }
    rec(0);
    printf("NO\n");
    return 0;
}