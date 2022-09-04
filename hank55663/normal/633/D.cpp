#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a[1005];
    map<int,int> m;
    map<int,int> m2;
    map<int,map<int,int> > aaa;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n==2)
        printf("2\n");
    else{
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        m[a[i]]++;
        int ans=0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
                if(i==j)
                continue;
            map<int,int> mm;
            int f1=a[i],f2=a[j];
            mm[f1]++;
            mm[f2]++;
            int aa=2;
            if(aaa[f1][f2]>=aa)
                continue;
            aaa[f1][f2]=aa;
            while(aaa[f1][f2]<=aa&&mm[f1+f2]!=m[f1+f2]){
                f2=f1+f2;
                f1=f2-f1;
                mm[f2]++;
                aa++;
                aaa[f1][f2]=aa;
            }
            ans=max(ans,aa);
        }
        printf("%d",ans);
    }
    return 0;
}