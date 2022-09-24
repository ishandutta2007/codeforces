#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL MOD=1e9+7;
vector<LL>emp;
struct matrix
{
    vector<vector<LL> >V;
    matrix()
    {
        V.clear();
    }
    inline matrix operator*(matrix x)
    {
        matrix ret;
        LL i,j,k,s;
        for(i=0;i<V.size();i++)
        {
            ret.V.push_back(emp);
            for(j=0;j<V.size();j++)
            {
                s=0;
                for(k=0;k<V.size();k++)
                    s=(s+V[i][k]*x.V[k][j])%MOD;
                ret.V[i].push_back(s);
            }
        }
        return ret;
    }
}mat,mul;
inline matrix Pow(matrix x,LL y)
{
    matrix ret;
    LL i,j;
    for(i=0;i<x.V.size();i++)
    {
        ret.V.push_back(emp);
        for(j=0;j<x.V.size();j++)
        {
            if(i==j)
                ret.V[i].push_back(1);
            else
                ret.V[i].push_back(0);
        }
    }
    while(y>0)
    {
        if(y&1)
            ret=ret*x;
        x=x*x;
        y>>=1;
    }
    return ret;
}
LL N,M,i,j;
LL dp[1234];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(i=0;i<M;i++)
        dp[i]=1;
    for(i=M;i<=M<<1;i++)
        dp[i]=(dp[i-1]+dp[i-M])%MOD;
    if(N<=M<<1)
        return cout<<dp[N]<<endl,0;
    for(i=0;i<M;i++)
    {
        mat.V.push_back(emp);
        mul.V.push_back(emp);
        for(j=0;j<M;j++)
        {
            mat.V[i].push_back(dp[M*2-i-j]);
            if(i==0)
            {
                if(j==0||j==M-1)
                    mul.V[i].push_back(1);
                else
                    mul.V[i].push_back(0);
            }
            else if(j==i-1)
                mul.V[i].push_back(1);
            else
                mul.V[i].push_back(0);
        }
    }
    mat=Pow(mul,N-M*2)*mat;
    cout<<mat.V[0][0]<<endl;
    return 0;
}