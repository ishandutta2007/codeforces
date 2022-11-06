#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>mem[2];
unordered_map<int,int>::iterator it;
int gcd(int x,int y){if (y==0) return x;if (x%y==0) return y;return gcd(y,x%y);}
int main(){
    int n,a,b=0,d;
    scanf("%d",&n);
    n--;
    scanf("%d %d",&a,&d);
    for (int i=2;i*i<=a;i++)if (a%i==0){while (a%i==0)a/=i;mem[0][i]=1;}
    if (a!=0)mem[0][a]=1;
    for (int i=2;i*i<=d;i++)if (d%i==0){while (d%i==0)d/=i;mem[0][i]=1;}
    if (d!=0)mem[0][d]=1;
    while(n--){
        b^=1;
        scanf("%d %d",&a,&d);
        mem[b].clear();
        for(it=mem[b^1].begin();it!=mem[b^1].end();it++){
            int y=gcd(a,it->first),z=gcd(d,it->first);
            mem[b][y]++;mem[b][z]++;
        }
    }
    for(it=mem[b].begin();it!=mem[b].end();it++){
    	if (it->first!=1){cout<<it->first<<endl;return 0;}
	}
	cout<<"-1"<<endl;
    return 0;
}