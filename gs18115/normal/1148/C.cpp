#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,i;
LL A[1000010],B[1000010];
vector<PL>V;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i++<N;i)
    {
        cin>>A[i];
        B[i]=A[i];
    }
    for(i=2;i<N;i++)
    {
        LL j=i;
        while((A[i]=B[i])!=i)
        {
            if(A[i]==1)
            {
                if(i-1<<1>=N)
                {
                    swap(B[1],B[i]);
                    V.eb(1,i);
                }
                else
                {
                    swap(B[i],B[N]);
                    V.eb(i,N);
                    swap(B[N],B[1]);
                    V.eb(1,N);
                }
                continue;
            }
            if(A[i]==N)
            {
                if(i-1<<1>=N)
                {
                    swap(B[1],B[i]);
                    V.eb(1,i);
                    swap(B[1],B[N]);
                    V.eb(1,N);
                }
                else
                {
                    swap(B[N],B[i]);
                    V.eb(i,N);
                }
                continue;
            }
            if(i-1<<1>=N)
            {
                swap(B[i],B[1]);
                V.eb(1,i);
                if(A[i]-1<<1>=N)
                {
                    swap(B[1],B[A[i]]);
                    V.eb(1,A[i]);
                }
                else
                {
                    swap(B[1],B[N]);
                    V.eb(1,N);
                    swap(B[N],B[A[i]]);
                    V.eb(A[i],N);
                }
            }
            else
            {
                swap(B[i],B[N]);
                V.eb(i,N);
                if(A[i]-1<<1>=N)
                {
                    swap(B[1],B[N]);
                    V.eb(1,N);
                    swap(B[1],B[A[i]]);
                    V.eb(1,A[i]);
                }
                else
                {
                    swap(B[N],B[A[i]]);
                    V.eb(A[i],N);
                }
            }
        }
    }
    if(B[1]!=1)
    {
        swap(B[1],B[N]);
        V.eb(1,N);
    }
    cout<<V.size();
    for(i=0;i<V.size();i++)
        cout<<'\n'<<V[i].fi<<' '<<V[i].se;
    cout<<endl;
    return 0;
}