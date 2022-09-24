#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,M,i,j,k;
LL A[1234];
bool chk[1234];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    chk[1]=chk[2]=chk[4]=chk[8]=chk[16]=true;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N;i++)
    {
        for(j=i;j<N;j++)
        {
            if(!chk[j-i+1]||i%(j-i+1)!=0)
                continue;
            for(k=i;k<j;k++)
                if(A[k]>A[k+1])
                    break;
            if(k>=j)
                M=max(M,j-i+1);
        }
    }
    cout<<M<<endl;
    return 0;
}