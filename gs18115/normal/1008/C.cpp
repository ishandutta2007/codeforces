#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL i,N,cnt,cnt1,cnt2;
LL a[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>a[i];
    sort(a,a+N,greater<LL>());
    cnt2=1;
    for(i=1;i<N;i++)
    {
        if(a[i]==a[i-1])
            cnt2++;
        else
        {
            cnt1+=cnt2;
            cnt2=1;
        }
        if(cnt1)
        {
            cnt++;
            cnt1--;
        }
    }
    cout<<cnt;
    return 0;
}