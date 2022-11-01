#include <bits/stdc++.h>

using namespace std;

int N;
string pats[100100];

int main()
{
    //freopen("in.txt", "r", stdin);
    cin>>N;
    cin.ignore();
    for(int i=0; i<N; i++)
        getline(cin, pats[i]);
    for(size_t i=0; i<pats[0].length(); i++)
    {
        int j;
        char let='\0';
        for(j=0; j<N; j++)
            if(pats[j][i]!='?' && pats[j][i]!=let)
            {
                if(!let)
                    let=pats[j][i];
                else
                {
                    let='?';
                    break;
                }
            }
        if(let)
            putchar(let);
        else
            putchar('x');
    }

    return 0;
}