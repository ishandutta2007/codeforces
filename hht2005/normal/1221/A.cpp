#include<bits/stdc++.h>
using namespace std;
int t[20];
int Log(int x) {
    int len=0;
    while(x)x>>=1,len++;
    return len-1;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
    	memset(t,0,sizeof(t));
        int n,a;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a);
            t[Log(a)]++;
        }
        for(int i=0;i<=12;i++)t[i+1]+=t[i]>>1;
        puts(t[11]?"YES":"NO");
    }
    return 0;
}