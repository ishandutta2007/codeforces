#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200+7;
int n, k, a[N], b[N], add[N], pr[N];
bool av[N];

int type(int x, int y, int a)
{
        return min(x, y)<=a && a<=max(x, y);
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

      ///  freopen ("input", "r", stdin);

        int t;
        cin>>t;
        while (t--)
        {
                cin>>n>>k;
                for (int i=0; i<2*n; i++)
                        av[i]=1;
                for (int i=1; i<=k; i++)
                {
                        cin>>a[i]>>b[i];
                        a[i]--;
                        b[i]--;
                        pr[a[i]]=b[i];
                        pr[b[i]]=a[i];
                        av[a[i]]=0;
                        av[b[i]]=0;
                }
                vector<int> pos;
                for (int i=0; i<2*n; i++)
                        if (av[i])
                                pos.push_back(i);
                assert((int) pos.size()==2*(n-k));
                for (int i=0; i<n-k; i++)
                {
                        int j=i+n-k;
                        a[k+1+i]=pos[i];
                        b[k+1+i]=pos[j];
                }
                for (int step=k+1; step<=n; step++)
                { continue;
                        int mx=-1, wi=-1, wj=-1;
                        for (int i=0; i<2*n; i++)
                        {
                                if (!av[i]) continue;
                                int avinside=0;
                                for (int k=0; k<2*n; k++) add[k]=0;
                                int cur=0;
                                for (int j=i+1; j<2*n; j++)
                                {
                                        if (av[j])
                                        {
                                                int avoutside=2*(n-step)-avinside;
                                                if (cur+min(avinside, avoutside)>mx)
                                                {
                                                        mx=cur+min(avinside, avoutside);
                                                        wi=i;
                                                        wj=j;
                                                }
                                                assert(add[j]==0);
                                                avinside++;
                                        }
                                        else
                                        {
                                                cur++;
                                                cur+=add[j];
                                                add[pr[j]]--;

                                        }
                                }
                        }
                        assert(mx!=-1);
                        av[wi]=0;
                        av[wj]=0;
                        a[step]=wi;
                        b[step]=wj;
                        pr[wi]=wj;
                        pr[wj]=wi;
                }
                int sol=0;
                for (int i=1; i<=n; i++)
                {
                        for (int j=i+1; j<=n; j++)
                                sol+=(type(a[i], b[i], a[j])!=type(a[i], b[i], b[j]));
                }
                cout<<sol<<"\n";
        }

        return 0;
}