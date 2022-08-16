#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    static const int N=10000005;
    static int smallestDivisor[N];
    static vector<int> primes;

    for(int i = 0; i <= N; i++)
        smallestDivisor[i] = i;

    for(int i = 2; i <= N; i++)
    {
        if(smallestDivisor[i] == i)
            primes.push_back(i);
        
        for(int j = 0; j < primes.size() && primes[j]*i <= N && primes[j] <= smallestDivisor[i]; j++)
            smallestDivisor[primes[j]*i] = primes[j];
    }

    int testcases;
    cin>>testcases;
    vector<pair<int,int>> answers;

    while(testcases--)
    {
        int n;
        cin>>n;

        int x = 1;
        int t = smallestDivisor[n];

        while(smallestDivisor[n]==t)
        {
            x*=t;
            n/=smallestDivisor[n];
        }

        if(n == 1)
            answers.push_back({-1,-1});
        else
            answers.push_back({x,n});
    }

    for(auto it:answers)
        cout<<it.first<<' ';
    cout<<'\n';
    for(auto it:answers)
        cout<<it.second<<' ';
    cout<<'\n';

    return 0;
}