#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int, long long int> p;

long long int n, k, t, b, ans, cnt;
p arr[300001];
long long int sum[300001];
priority_queue <int> pQ;

int main()
{
    cin>>n>>k;

    for(int i=0; i<n; i++)
    {
        cin>>t>>b;
        arr[i]={b, t};
    }

    sort(arr, arr+n);

    for(int i=n-1; i>=0; i--)
    {
        if(pQ.size()<k) pQ.push(-arr[i].second), cnt+=arr[i].second;
        else if(arr[i].second > -pQ.top())
        {
            cnt-= -pQ.top();
            cnt+=arr[i].second;
            pQ.pop();
            pQ.push(-arr[i].second);
        }

        sum[i]=cnt;
    }

    for(int i=0; i<n; i++)
    {
        b=arr[i].first;
        if(ans < b*sum[i]) ans = b*sum[i];
    }

    cout<<ans;
}