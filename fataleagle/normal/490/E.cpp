#include <bits/stdc++.h>

using namespace std;

int N;
char buf[9];
char A[100000][9];
int msd[100000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%s", buf);
        int M=strlen(buf);
        for(int j=0; j<8-M; j++)
            A[i][j]='0';
        for(int j=0; j<M; j++)
            A[i][j+8-M]=buf[j];
        msd[i]=8-M;
    }
    memset(buf, '0', sizeof buf);
    buf[8]='\0';
    int ov=0;
    for(int i=0; i<N; i++)
    {
        vector<int> ques;
        for(int j=0; j<8; j++)
            if(A[i][j]=='?')
            {
                A[i][j]='9';
                ques.push_back(j);
            }
        if(atoi(A[i])<=ov)
        {
            printf("NO\n");
            return 0;
        }
        for(auto& j: ques)
            while(A[i][j]>'1' || ((j!=ques[0] || ques[0]!=msd[i]) && A[i][j]>'0'))
            {
                A[i][j]--;
                if(atoi(A[i])<=ov)
                {
                    A[i][j]++;
                    break;
                }
            }
        strcpy(buf, A[i]);
        ov=atoi(buf);
    }
    printf("YES\n");
    for(int i=0; i<N; i++)
    {
        bool lz=true;
        for(int j=0; j<8; j++)
        {
            lz=lz && A[i][j]=='0';
            if(!lz)
                putchar(A[i][j]);
        }
        putchar('\n');
    }
    return 0;
}