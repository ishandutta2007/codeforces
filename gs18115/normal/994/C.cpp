#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
typedef vector<LL>VL;
const int N=4;
const int dx[4]={1,-1,-1,1},dy[4]={1,1,-1,-1};
bool chk[567][567];
int xmi1,xma1,ymi1,yma1,xmi2,xma2,ymi2,yma2;
int i,j,k,K;
int a[4][2],b[4][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    xmi1=ymi1=xmi2=ymi2=9999999;
    for(i=0;i<N;i++)
    {
        cin>>a[i][0]>>a[i][1];
        a[i][0]+=200;
        a[i][1]+=200;
        if(xmi1>a[i][0])
            xmi1=a[i][0];
        if(xma1<a[i][0])
            xma1=a[i][0];
        if(ymi1>a[i][1])
            ymi1=a[i][1];
        if(yma1<a[i][1])
            yma1=a[i][1];
    }
    for(i=0;i<N;i++)
    {
        cin>>b[i][0]>>b[i][1];
        b[i][0]+=200;
        b[i][1]+=200;
        if(xmi2>b[i][0])
            xmi2=b[i][0];
        if(xma2<b[i][0])
            xma2=b[i][0];
        if(ymi2>b[i][1])
            ymi2=b[i][1];
        if(yma2<b[i][1])
            yma2=b[i][1];
    }
    for(i=xmi1;i<=xma1;i++)
        for(j=ymi1;j<=yma1;j++)
            chk[i][j]=true;
    for(i=xmi2;i<=xma2;i++)
    {
        for(j=ymi2;j<=yma2;j++)
        {
            if(chk[i][j]&&i+j<=yma2+(xmi2+xma2>>1)&&i+j>=ymi2+(xmi2+xma2>>1)&&i-j<=(xmi2+xma2>>1)-ymi2&&i-j>=(xmi2+xma2>>1)-yma2)
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}