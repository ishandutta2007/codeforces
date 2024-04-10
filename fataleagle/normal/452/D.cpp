#include <bits/stdc++.h>

using namespace std;

int K, N1, N2, N3, T1, T2, T3;
priority_queue<int, vector<int>, greater<int>> washer, dryer, folder;

int main()
{
    cin>>K>>N1>>N2>>N3>>T1>>T2>>T3;
    for(int i=0; i<=30000300; i++)
    {
        while(!folder.empty() && folder.top()<=i)
            folder.pop();
        while(!dryer.empty() && dryer.top()<=i && (int)folder.size()<N3)
            dryer.pop(), folder.push(i+T3);
        while(!washer.empty() && washer.top()<=i && (int)dryer.size()<N2)
            washer.pop(), dryer.push(i+T2);
        while(K>0 && (int)washer.size()<N1)
            K--, washer.push(i+T1);
        if(K==0 && washer.empty() && dryer.empty() && folder.empty())
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}