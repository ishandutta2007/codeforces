#include <bits/stdc++.h>

using namespace std;

int N;
char S[20];
int has[10];

int main()
{
    scanf("%d", &N);
    scanf("%s", S);
    for(int i=0; i<N; i++)
        for(int j=2; j<=S[i]-'0'; j++)
            has[j]++;
    vector<int> ans;
    vector<int> more;
    for(int i=9; i>=2; i--)
    {
        more.clear();
        while(has[i]>0)
        {
            has[i]--;
            int x=i;
            for(int j=2; j<=x; j++)
                while(x%j==0)
                {
                    more.push_back(j);
                    x/=j;
                }
        }
        for(auto& it: more)
            has[it]++;
        while(has[i]>0)
        {
            for(int j=2; j<=i; j++)
                has[j]--;
            ans.push_back(i);
        }
    }
    sort(ans.rbegin(), ans.rend());
    for(auto& it: ans)
        printf("%d", it);
    printf("\n");
    return 0;
}