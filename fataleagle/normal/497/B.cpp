#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> A, B;
vector<pair<int, int>> ans;

void solve(int t)
{
    int s1=0, s2=0;
    int pos1=-1, pos2=-1;
    while(1)
    {
        int new1=pos1+t;
        int new2=pos2+t;
        if(new1>=(int)A.size() && new2>=(int)B.size())
            break;
        if(new1>=(int)A.size())
        {
            while(pos2+1<(int)B.size())
            {
                s2++;
                pos2+=t;
            }
            if(pos2+1==(int)B.size() && s2>s1 && B.back()==N-1)
                ans.push_back(make_pair(s2, t));
            break;
        }
        if(new2>=(int)B.size())
        {
            while(pos1+1<(int)A.size())
            {
                s1++;
                pos1+=t;
            }
            if(pos1+1==(int)A.size() && s1>s2 && A.back()==N-1)
                ans.push_back(make_pair(s1, t));
            break;
        }
        if(A[new1]<B[new2])
        {
            s1++;
            pos1=new1;
            pos2=lower_bound(B.begin(), B.end(), A[new1])-B.begin()-1;
        }
        else
        {
            s2++;
            pos2=new2;
            pos1=lower_bound(A.begin(), A.end(), B[new2])-A.begin()-1;
        }
    }
}

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        if(a==1)
            A.push_back(i);
        else
            B.push_back(i);
    }
    int M=max(A.size(), B.size());
    for(int i=1; i<=M; i++)
        solve(i);
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for(auto& it: ans)
        printf("%d %d\n", it.first, it.second);
    return 0;
}