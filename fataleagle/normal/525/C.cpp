#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000005];
int B[1000005];

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        A[a]++;
    }
    vector<int> v;
    for(int i=1000000; i>=1; i--)
    {
        if(((A[i]+B[i])&1) && A[i]>0)
            A[i]--, B[i-1]++;
        int tmp=max(0, (A[i]+B[i])/2);
        while(tmp--)
            v.push_back(i);
    }
    reverse(v.begin(), v.end());
    long long ans=0;
    while(v.size()>=2)
    {
        ans+=1LL*v.back()*v[v.size()-2];
        v.pop_back();
        v.pop_back();
    }
    cout<<ans<<endl;
    return 0;
}