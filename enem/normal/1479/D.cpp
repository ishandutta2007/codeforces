#include<bits/stdc++.h>
using namespace std;

static const int N = 300005, B = 550;
static int n, q, a[N], st[N], en[N], v[2*N], pt, par[N][20], hgt[N], ans[N];
static vector<int> ad[N];
static tuple<int, int, int, int, int, int> b[N];

bool xd(tuple<int, int, int, int, int, int> &x, tuple<int, int, int, int, int, int> &y)
{
    if(get<0>(x)/B != get<0>(y)/B) return get<0>(x) < get<0>(y);
    return get<1>(x) < get<1>(y);
}

void dfs(int x, int y)
{
    if(y!=-1)
    {
        par[x][0] = y;
        hgt[x] = hgt[y] + 1;
    }
    else
    {
        par[x][0] = x;
        hgt[x] = 0;
    }

    for(int j=1; j<20; j++)
    {
        par[x][j] = par[par[x][j-1]][j-1];
    }

    v[pt]=a[x];
    st[x]=pt;
    pt++;

    for(auto it : ad[x])
    {
        if(it!=y)
        {
            dfs(it,x);
        }
    }

    v[pt]=a[x];
    en[x]=pt;
    pt++;

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        a[i]--;
    }

    for(int i=0; i<n-1; i++)
    {
        int t1, t2;
        cin>>t1>>t2;
        t1--;t2--;

        ad[t1].push_back(t2);
        ad[t2].push_back(t1);
    }

    dfs(0,-1);

    for(int i=0; i<q; i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        t1--;t2--;

        int l = t1;
        int r = t2;

        for(int j=19; j>=0; j--)
        {
            if(hgt[l]+(1<<j)<=hgt[r])
            {
                r = par[r][j];
            }
            if(hgt[r]+(1<<j)<=hgt[l])
            {
                l = par[l][j];
            }
        }

        if(l==r)
        {
            if(t1 == l)
            {
                get<0>(b[i]) = st[t1];
                get<1>(b[i]) = st[t2]+1;
            }
            else
            {
                get<0>(b[i]) = st[t2];
                get<1>(b[i]) = st[t1]+1;
            }
            get<2>(b[i]) = -1;
        }
        else
        {
            for(int j=19; j>=0; j--)
            {
                if(par[l][j] != par[r][j])
                {
                    l = par[l][j];
                    r = par[r][j];
                }
            }

            if(en[t1]<st[t2])
            {
                get<0>(b[i]) = en[t1];
                get<1>(b[i]) = st[t2]+1;
            }
            else
            {
                get<0>(b[i]) = en[t2];
                get<1>(b[i]) = st[t1]+1;
            }
            get<2>(b[i]) = a[par[l][0]];
        }

        cin>>get<3>(b[i])>>get<4>(b[i]);
        get<3>(b[i])--;
        get<4>(b[i])--;
        get<5>(b[i]) = i;
    }

    sort(b, b+q, xd);

    int l=0,r=0;
    unsigned long long mp[(n+63)/64]={};

    for(int i=0; i<q; i++)
    {
        int tl = get<0>(b[i]);
        int tr = get<1>(b[i]);
        int lca = get<2>(b[i]);

        while(l<tl)
        {
            mp[v[l]>>6]^=(1LL<<(v[l]&((1<<6)-1)));
            l++;
        }
        while(l>tl)
        {
            l--;
            mp[v[l]>>6]^=(1LL<<(v[l]&((1<<6)-1)));
        }
        while(r<tr)
        {
            mp[v[r]>>6]^=(1LL<<(v[r]&((1<<6)-1)));
            r++;
        }
        while(r>tr)
        {
            r--;
            mp[v[r]>>6]^=(1LL<<(v[r]&((1<<6)-1)));
        }

        if(lca!=-1)
        {
            mp[lca>>6]^=(1LL<<(lca&((1<<6)-1)));
        }

        tl = get<3>(b[i]);
        tr = get<4>(b[i]);

        int pt = -2;

        if((tl>>6)==(tr>>6))
        {
            for(int j=tl; j<=tr; j++)
            {
                if((mp[j>>6]&(1LL<<(j&((1<<6)-1))))!=0)
                {
                    pt = j;
                    break;
                }
            }
        }
        else
        {
            while((tl>>6)==((tl-1)>>6))
            {
                if((mp[tl>>6]&(1LL<<(tl&((1<<6)-1))))!=0)
                {
                    pt = tl;
                    break;
                }
                tl++;
            }

            if(pt==-2)
            {

                while((tr>>6)==((tr+1)>>6))
                {
                    if((mp[tr>>6]&(1LL<<(tr&((1<<6)-1))))!=0)
                    {
                        pt = tr;
                        break;
                    }
                    tr--;
                }

                if(pt==-2)
                {

                    for(int j=(tl>>6); j<=(tr>>6); j++)
                    {
                        if(mp[j]!=0)
                        {
                            pt = __builtin_ctzll(mp[j])+(j<<6);
                            break;
                        }
                    }
                }
            }
        }

        ans[get<5>(b[i])] = pt+1;

        if(lca!=-1)
        {
            mp[lca>>6]^=(1LL<<(lca&((1<<6)-1)));
        }
    }

    for(int i=0; i<q; i++)
    {
        cout<<ans[i]<<'\n';
    }

    return 0;
}