#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> ans;
    for(int i=0; i<N; i++)
    {
        ans.push_back(1);
        while(ans.size()>=2 && ans.back()==ans[ans.size()-2])
        {
            int x=ans.back();
            ans.pop_back();
            ans.pop_back();
            ans.push_back(x+1);
        }
    }
    for(int i=0; i<(int)ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}