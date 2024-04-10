#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+7;
int kek;

int tree[4*N*N], lazy[4*N*N];

void push(int v, int tl, int tr)
{
        if (!lazy[v]) return;
        tree[v]+=lazy[v];
        if (tl<tr)
        {
                lazy[2*v]+=lazy[v];
                lazy[2*v+1]+=lazy[v];
        }
        lazy[v]=0;
}

void add(int v, int tl, int tr, int l, int r, int x)
{
        push(v, tl, tr);
        if (tr<l||r<tl)
                return;
        if (l<=tl&&tr<=r)
        {
                lazy[v]+=x;
                push(v, tl, tr);
                return;
        }
        int tm=(tl+tr)/2;
        add(2*v, tl, tm, l, r, x);
        add(2*v+1, tm+1, tr, l, r, x);
        tree[v]=min(tree[2*v], tree[2*v+1]);
}

int get(int v, int tl, int tr, int l, int r)
{
        push(v, tl, tr);
        if (tr<l||r<tl) return (int) 1e9;
        if (l<=tl&&tr<=r)
        {
                return tree[v];
        }
        int tm=(tl+tr)/2;
        return min(get(2*v, tl, tm, l, r), get(2*v+1, tm+1, tr, l, r));
}

void build(int v=1, int tl=1, int tr=kek)
{
        tree[v]=lazy[v]=0;
        if (tl<tr)
        {
                int tm=(tl+tr)/2;
                build(2*v, tl, tm);
                build(2*v+1, tm+1, tr);
        }
}

void add(int l, int r, int x)
{
        add(1, 1, kek, l, r, x);
}

int get(int l, int r)
{
        return get(1, 1, kek, l, r);
}

int dv(int n, int k)
{
        return (n+k-1)/k;
}

int ke[N][2];

void solve(int n, int k, vector<int> v)
{
        kek=n*k;
        build();
        add(1, kek, dv(n, k-1));
        for (auto &x : v) x--;

        ///vector<bool> done(n, 0);
        vector<pair<int, int>> sol;
        vector<bool> done(n, 0);
        vector<int> fr(n, 0), ant(n);
        for (int i=0; i<n*k; i++)
        {
                fr[v[i]]++;
                if (fr[v[i]]>=2 && !done[v[i]])
                {
                        int j=ant[v[i]];
                        if (get(j, i)>0)
                        {
                                add(j, i, -1);
                                done[v[i]]=1;
                                //cout<<"yoo : "<<v[j]<<" and "<<v[i]<<"\n";
                                ke[v[i]][0]=j;
                                ke[v[j]][1]=i;
                                sol.push_back({j, i});
                        }
                }
                ant[v[i]]=i;
        }
       /** assert((int) sol.size()==n);
        vector<int> gauss(n*k, 0);
        for (auto &it : sol)
        {
                gauss[it.first]++;
                if (it.second+1<n*k)
                {
                        gauss[it.second+1]--;
                }
        }
        for (int i=1; i<n*k; i++)
                gauss[i]+=gauss[i-1];
        for (int i=0; i<n*k; i++)
                assert(gauss[i]<=dv(n, k-1));**/
        for (int i=0; i<n; i++)
                cout<<ke[i][0]+1<<" "<<ke[i][1]+1<<"\n";
        return;
        for (auto &it : sol)
                cout<<it.first+1<<" "<<it.second+1<<"\n";
}


signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        int n, k;
        cin>>n>>k;
        vector<int> v(n*k);
        for (auto &x : v)
                cin>>x;
        solve(n, k, v);


        return 0;
}