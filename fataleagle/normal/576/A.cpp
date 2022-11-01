#include <bits/stdc++.h>

using namespace std;

int N;
bool prime[1001];

int main()
{
    scanf("%d", &N);
    for(int i=2; i<=N; i++)
        prime[i]=true;
    for(int i=2; i<=N; i++) if(prime[i])
    {
        for(int j=i*2; j<=N; j+=i)
            prime[j]=false;
    }
    vector<int> ans;
    for(int i=2; i<=N; i++) if(prime[i])
    {
        int x=i;
        while(x<=N)
        {
            ans.push_back(x);
            x*=i;
        }
    }
    printf("%d\n", ans.size());
    for(size_t i=0; i<ans.size(); i++)
        printf("%d%c", ans[i], " \n"[i+1==ans.size()]);
    return 0;
}