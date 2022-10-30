#include <bits/stdc++.h>

using namespace std;

int N;
int A[150000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    if(N<100)
    {
        int ans=0;
        for(int i=0; i<N; i++)
        {
            for(int j=i+1; j<N; j++)
            {
                swap(A[i], A[j]);
                bool ok=true;
                for(int k=0; k<N-1 && ok; k++)
                {
                    if(k%2==0)
                        ok&=A[k]<A[k+1];
                    else
                        ok&=A[k]>A[k+1];
                }
                if(ok)
                    ans++;
                swap(A[i], A[j]);
            }
        }
        printf("%d\n", ans);
        return 0;
    }
    vector<int> bad;
    for(int i=1; i<N; i++)
    {
        if(i%2==1 && A[i]<=A[i-1])
            bad.push_back(i);
        else if(i%2==0 && A[i]>=A[i-1])
            bad.push_back(i);
    }
    if(bad.size()>=10)
        printf("0\n");
    else
    {
        set<pair<int, int>> ans;
        vector<int> cand;
        for(auto& it: bad)
        {
            for(int j=it-3; j<=it+3; j++) if(0<=j && j<N)
                cand.push_back(j);
        }
        cand.push_back(0);
        cand.push_back(1);
        cand.push_back(N-2);
        cand.push_back(N-1);
        sort(cand.begin(), cand.end());
        cand.resize(unique(cand.begin(), cand.end())-cand.begin());
        for(auto& i: cand)
        {
            for(int j=0; j<N; j++) if(i!=j)
            {
                swap(A[i], A[j]);
                bool ok=true;
                cand.push_back(j-1);
                cand.push_back(j);
                cand.push_back(j+1);
                for(auto& k: cand)
                {
                    if(k-2>=0)
                    {
                        if(k%2==0 && A[k-1]-A[k-2]<=0)
                            ok=false;
                        else if(k%2==1 && A[k-1]-A[k-2]>=0)
                            ok=false;
                    }
                    if(k-1>=0)
                    {
                        if(k%2==1 && A[k]-A[k-1]<=0)
                            ok=false;
                        else if(k%2==0 && A[k]-A[k-1]>=0)
                            ok=false;
                    }
                    if(k+1<N)
                    {
                        if(k%2==0 && A[k+1]-A[k]<=0)
                            ok=false;
                        else if(k%2==1 && A[k+1]-A[k]>=0)
                            ok=false;
                    }
                    if(!ok)
                        break;
                }
                cand.pop_back();
                cand.pop_back();
                cand.pop_back();
                if(ok)
                    ans.insert(make_pair(min(i, j), max(i, j)));
                swap(A[i], A[j]);
            }
        }
        printf("%d\n", ans.size());
    }
    return 0;
}