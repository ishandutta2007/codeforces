#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    int a[200005];
    int b[200005];
    a[0]=b[0]=0;
    for(int i = 1;i<n;i++){
        scanf("%d",&a[i]);
    //    a[i]+=a[i-1];
    }
    for(int i = 1;i<n;i++){
        scanf("%d",&b[i]);
    //    b[i]+=b[i-1];
    }
    int aa=0,bb=0;
    for(int i=0;i<n;i++){
        //printf("%d ",min(a[i],b[i]+c));
        printf("%d ",min(aa,bb+c));
        aa=min(aa,min(aa,bb+c));
        bb=min(bb,min(aa,bb+c));
        aa+=a[i+1];
        bb+=b[i+1];
    }
}