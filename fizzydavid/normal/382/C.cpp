#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define end1 cout<<"-1";return 0;
#define end2 cout<<"0";return 0;
long long n,d=-1,a[100005];
int main()
{
    bool f=false;
    long long x1,x2,i,j,c;
    cin>>n;
    if(n==1){cin>>x1;end1}
    else if(n==2)
    {
        cin>>x1>>x2;
        if(x1!=x2)
        {
            cout<<2+((max(x1,x2)-min(x1,x2))%2==0)<<endl;
            cout<<min(x1,x2)*2-max(x1,x2)<<" ";
            if((max(x1,x2)-min(x1,x2))%2==0)cout<<(max(x1,x2)+min(x1,x2))/2<<" ";
            cout<<max(x1,x2)*2-min(x1,x2);
        }
        else cout<<"1"<<endl<<x1;
    }
    else
    {
        c=0;
        for(i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        for(i=1;i<n;i++)
        {
            if(max(a[i]-a[i-1],d)==(min(a[i]-a[i-1],d)*2)&&d!=0||a[i]-a[i-1]==d||d==-1)
            {
                if(max(a[i]-a[i-1],d)==min(a[i]-a[i-1],d)*2&&d!=0)
                {
                    if(f==true){end2}
                    if((a[i]-a[i-1])<d&&c>1){end2}
                    d=min(a[i]-a[i-1],d);f=true;c++;
                }
                else if(d==-1)d=a[i]-a[i-1];c++;
            }
            else {end2}
        }
        if(f==false)
        {
            if(d!=0)cout<<"2"<<endl<<a[0]-d<<" "<<a[n-1]+d;
            else cout<<"1"<<endl<<a[0];
        }
        else 
        {
             cout<<"1"<<endl;
             for(i=0;i<n-1;i++)if(a[i]+d*2==a[i+1]){cout<<a[i]+d;break;}
        }
    }
    return 0;
}