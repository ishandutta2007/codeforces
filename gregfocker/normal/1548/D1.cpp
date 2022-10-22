#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll


struct pt
{
        int x, y;
};

pt dv(pt a)
{
        assert(a.x%2==0);
        assert(a.y%2==0);
        a.x/=2;
        a.y/=2;
        return a;
}


int geto(pt a, pt b)
{
        int dx=abs(a.x-b.x);
        int dy=abs(a.y-b.y);
        dx%=2;
        dy%=2;
        return (dx==0&&dy==0);
}

const int N=6000+7;
int n;
pt v[N];


int cnt[2][2];

int smart(vector<pt> a)
{
        for (auto &it : a)
        {
                it.x=abs(it.x);
                it.y=abs(it.y);
        }
        int n=(int) a.size(), sol=0;
        cnt[0][0]=cnt[0][1]=cnt[1][0]=cnt[1][1]=0;
        for (int i=0; i<n; i++)
        {
                cnt[a[i].x%2][a[i].y%2]++;
        }
        for (int i=0; i<n; i++)
        {
                cnt[a[i].x%2][a[i].y%2]--;
                for (int x=0; x<2; x++)
                {
                        for (int y=0; y<2; y++)
                        {
                                int sum=geto(a[i], {x, y})+geto({x, y}, {0, 0})+geto({0, 0}, a[i]);
                                sol+=cnt[x][y]*(sum%2==1);
                        }
                }

        }
        return sol;
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n;
        for (int i=1; i<=n; i++)
                cin>>v[i].x>>v[i].y;


        int sol=0;

        for (int i=1; i<=n; i++)
                v[i]=dv(v[i]);

        for (int i=1; i<=n; i++)
        {
                vector<pt> kek;
                for (int j=i+1; j<=n; j++)
                        kek.push_back({v[j].x-v[i].x, v[j].y-v[i].y});

                sol+=smart(kek);
        }

        cout<<sol<<"\n";
        return 0;
}