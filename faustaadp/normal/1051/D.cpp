#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,d[4][1010][2020],has,mo=998244353;
ll depe(ll aa,ll bb,ll cc)
{
    if(cc<0)
        return 0;
    if(bb==n&&cc==0)
        return 1;
    if(bb==n)
        return 0;
    if(d[aa][bb][cc]==-1)
    {
        d[aa][bb][cc]=depe(aa,bb+1,cc);
        if(aa==0) d[aa][bb][cc]=(d[aa][bb][cc]+depe(1,bb+1,cc-1)+depe(2,bb+1,cc-1)+depe(3,bb+1,cc-1))%mo;
        if(aa==1) d[aa][bb][cc]=(d[aa][bb][cc]+depe(0,bb+1,cc)+depe(2,bb+1,cc-2)+depe(3,bb+1,cc))%mo;
        if(aa==2) d[aa][bb][cc]=(d[aa][bb][cc]+depe(0,bb+1,cc)+depe(1,bb+1,cc-2)+depe(3,bb+1,cc))%mo;
        if(aa==3) d[aa][bb][cc]=(d[aa][bb][cc]+depe(0,bb+1,cc-1)+depe(1,bb+1,cc-1)+depe(2,bb+1,cc-1))%mo;
    }
    return d[aa][bb][cc];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	memset(d,-1,sizeof(d));
    has=(depe(0,1,m-1)+depe(1,1,m-2)+depe(2,1,m-2)+depe(3,1,m-1))%mo;
    cout<<has<<"\n";
}