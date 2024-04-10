#include <bits/stdc++.h>

using namespace std;

char S[200001];

int main()
{
    int N;
    scanf("%d", &N);
    scanf("%s", S);
    queue<int> D, R;
    for(int i=0; i<N; i++)
    {
        if(S[i]=='D')
            D.push(i);
        else
            R.push(i);
    }
    while(!D.empty() && !R.empty())
    {
        if(D.front()<R.front())
            D.push(D.front()+N);
        else
            R.push(R.front()+N);
        D.pop();
        R.pop();
    }
    if(D.empty())
        printf("R\n");
    else
        printf("D\n");
    return 0;
}