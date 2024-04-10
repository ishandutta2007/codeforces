#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n;
long long ans;
long long a[N][2],d[N];
bool sig[2],isd[2],bz[3];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    long long last0=-1e9,last1=-1e9;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        char c;
        cin>>c;
        a[i][0]=x;
        if (c=='P')a[i][1]=2,bz[2]=1;
        else
        if (c=='R')a[i][1]=0,bz[0]=1;
        else
            a[i][1]=1,bz[1]=1;
    }
    if (bz[2]){
            int last2=0;
            for (int i=1;i<=n;i++)
                if (a[i][1]==2){
                    if (last2){
                        d[0]=0;
                        for (int j=last2;j<=i;j++)
                            if (a[j][1]==2||a[j][1]==1)d[++d[0]]=a[j][0];
                        long long x=0,s=0;
                        bool bz=1,bz1=1;
                        for (int j=1;j<d[0];j++)
                            s=max(s,d[j+1]-d[j]);
                        x=s;
                        if (d[0]==2)bz=0;
                        s=0; 
                        d[0]=0;
                        for (int j=last2;j<=i;j++)
                            if (a[j][1]==2||a[j][1]==0)d[++d[0]]=a[j][0];
                        for (int j=1;j<d[0];j++)
                            s=max(s,d[j+1]-d[j]);
                        if (d[0]==2)bz1=0;
                        if (bz||bz1){
                            ans+=min((a[i][0]-a[last2][0])*2,(a[i][0]-a[last2][0])*3-x-s);
                        }else
                            ans+=(a[i][0]-a[last2][0]);
                    }else{
                        for (int j=1;j<i;j++)
                            if (a[j][1]==1){
                                ans+=a[i][0]-a[j][0];
                                break;
                            }
                        for (int j=1;j<i;j++)
                            if (a[j][1]==0){
                                ans+=a[i][0]-a[j][0];
                                break;
                            }
                    }
                    last2=i;
                }
            for (int j=n;j>last2;j--)
                if (a[j][1]==1){
                    ans+=a[j][0]-a[last2][0];
                    break;
                }
            for (int j=n;j>last2;j--)
                if (a[j][1]==0){
                    ans+=a[j][0]-a[last2][0];
                    break;
                }
    }else{
        for (int i=1;i<=n;i++){
            int x=a[i][0];
            if (a[i][1]==0){
                if (!sig[0])sig[0]=1,last0=x,isd[0]=0;
                ans+=x-last0;
                last0=x;
                isd[0]=0;
            }else{
                if (!sig[1])sig[1]=1,last1=x,isd[1]=0;
                ans+=x-last1;
                last1=x;
                isd[1]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}