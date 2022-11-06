#include<bits/stdc++.h>
using namespace std;
int t,n,m,a;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a),m-=a;
        puts(m==0?"YES":"NO");
    }
    return 0;
}