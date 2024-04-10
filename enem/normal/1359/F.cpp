//https://codeforces.com/contest/1359/problem/F
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int x[n],y[n],dx[n],dy[n],s[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>dx[i]>>dy[i]>>s[i];
    }
    float ans=-1;
    int eff_s;
    float t1,t2;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(dx[i]*dy[j]==dx[j]*dy[i])
            {
                if(dx[i]*(y[j]-y[i])==dy[i]*(x[j]-x[i]))
                {
                    eff_s=0;
                    if(dy[i]*(y[j]-y[i])>0)
                        eff_s+=s[i];
                    if(dy[j]*(y[i]-y[j])>0)
                        eff_s+=s[j];
                    if(eff_s!=0)
                    {
                        t1=sqrt((y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i]))/eff_s;
                        if(ans==-1||ans>t1)
                        {
                            ans=t1;
                        }
                    }
                }
            }
            else
            {
                t1=(sqrt(dx[i]*dx[i]+dy[i]*dy[i])*(dy[j]*(x[j]-x[i])-dx[j]*(y[j]-y[i])))/(s[i]*(dx[i]*dy[j]-dx[j]*dy[i]));
                t2=(sqrt(dx[j]*dx[j]+dy[j]*dy[j])*(dy[i]*(x[i]-x[j])-dx[i]*(y[i]-y[j])))/(s[j]*(dx[j]*dy[i]-dx[i]*dy[j]));
                if(t1>=0&&t2>=0&&(ans==-1||ans>max(t1,t2)))
                {
                    ans=max(t1,t2);
                }
            }
        }
    }
    if(ans==-1)
        cout<<"No show :(";
    else
        cout<<setprecision(14)<<ans;

    return 0;
}