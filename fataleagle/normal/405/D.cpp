#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000
#define opp(x) (1000001-x)

enum person
{
    _, X, Y, Z
};

int N;
int used[1000001];
vector<int> output;

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        used[a]=X;
    }
    int l=1;
    for(int i=1; i<=MAXN; i++)
        if(used[i]==X)
        {
            if(used[opp(i)]==X)
            {
                while(l<=MAXN && !(!used[l] && !used[opp(l)]))
                    l++;
                used[l]=used[opp(l)]=Y;
                used[i]=used[opp(i)]=Z;
                l++;
            }
            else
            {
                used[i]=Z;
                used[opp(i)]=Y;
            }
        }
    for(int i=1; i<=MAXN; i++)
        if(used[i]==Y)
            output.push_back(i);
    printf("%d\n", output.size());
    for(unsigned int i=0; i<output.size(); i++)
        printf("%d ", output[i]);
    printf("\n");

    return 0;
}