#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,re,cnt,i,a[1010],x;
    cin >> n;
    for (i=1;i<=1000;i++) a[i]=0;
    for (i=1;i<=n;i++) 
    {
        cin >> x;
        a[x]++;
    }
    cnt=0; re=0;
    for (i=1;i<=1000;i++)
    {
        if (a[i]!=0) cnt++;
        re=max(re,a[i]);
    }            
    cout << re << " " << cnt << endl;
    return 0;
}