#include <bits/stdc++.h>

using namespace std;

map<char, int> W;
char buf[10];
int white, black;

int main()
{
    W['Q']=9;
    W['R']=5;
    W['B']=3;
    W['N']=3;
    W['P']=1;
    W['K']=0;
    for(int i=0; i<8; i++)
    {
        scanf("%s", buf);
        for(int j=0; j<8; j++) if(isalpha(buf[j]))
        {
            if(islower(buf[j]))
                black+=W[toupper(buf[j])];
            else
                white+=W[buf[j]];
        }
    }
    if(white>black)
        printf("White\n");
    else if(white<black)
        printf("Black\n");
    else
        printf("Draw\n");
    return 0;
}