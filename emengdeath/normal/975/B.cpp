#include<bits/stdc++.h>
using namespace std;
long long a[15],b[15];
long long ans;
int main(){
    ios::sync_with_stdio(false);
    for (int i=1;i<=14;i++){
        cin>>a[i];
        if (a[i]%2==0)ans+=a[i];
    }
    for (int i=1;i<=14;i++){
        if (!a[i])continue;
        for (int j=1;j<=14;j++)
            if (i==j)b[j]=0;
            else
                b[j]=a[j];
        int sum=1;
        int k=i%14+1;
        int v=a[i]/14,u=a[i]%14;
        while (1){
            b[k]+=v+(sum<=u);
            if (k==i)break;
            sum++;
            k=k%14+1;
        }
        long long s=0;
        for (int j=1;j<=14;j++)
            if (b[j]%2==0)s+=b[j];
        ans=max(ans,s);
    }
    cout<<ans;
    return 0;
}