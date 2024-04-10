#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const LL MAXN=3e6+10;
LL N,i,A;
bool flag;
LL cur,cnt;
LL p[MAXN];
bool chk[MAXN],pchk[MAXN];
vector<LL>V;
inline bool check(LL X)
{
    V.clear();
    for(LL i=0;p[i]*p[i]<=X&&i<cnt;i++)
    {
        if(X%p[i]==0)
        {
            V.push_back(p[i]);
            while(X%p[i]==0)
                X/=p[i];
        }
    }
    if(X!=1)
        V.push_back(X);
    for(LL i=0;i<V.size();i++)
        if(chk[V[i]])
            return false;
    return true;
}
inline void checking()
{
    for(LL i=0;i<V.size();i++)
        chk[V[i]]=true;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(i=2;i<MAXN;i++)
        pchk[i]=true;
    for(i=2;i<MAXN;i++)
    {
        if(pchk[i])
        {
            p[cnt++]=i;
            for(LL j=i*i;j<MAXN;j+=i)
                pchk[j]=false;
        }
    }
    cur=1;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A;
        if(flag)
        {
            while(cur<MAXN)
            {
                cur++;
                if(check(cur))
                    break;
            }
            checking();
            A=cur;
        }
        else
        {
            if(check(A))
                checking();
            else
            {
                LL j=A;
                while(j<MAXN)
                {
                    if(check(++j))
                        break;
                }
                checking();
                A=j;
                flag=true;
            }
        }
        cout<<A<<' ';
    }
    cout<<endl;
    return 0;
}