#include <bits/stdc++.h>

using namespace std;

int N;
char S[100];

int main()
{
    scanf("%s", S);
    N=strlen(S);
    vector<int> ans;
    while(1)
    {
        int num=0;
        for(int i=0; i<N; i++)
        {
            num*=10;
            if(S[i]!='0')
                num++, S[i]--;
        }
        if(!num)
            break;
        ans.push_back(num);
    }
    printf("%d\n", ans.size());
    for(auto& it: ans)
        printf("%d ", it);
    printf("\n");
    return 0;
}