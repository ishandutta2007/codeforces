#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct block
{
    bool emptyblockshere;
    char block[5];
};

block blocks[101];
Int bL=0;
Int n;

int main()
{
    Int i,j,in;
    string s;
    char currentblocks[5];
    Int cbL=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        bL=0;
        cbL=0;
        cin>>s;
        if (s[0]==':')
        {
            bL=1;
            blocks[1].emptyblockshere=true;
            for (j=2;j<s.length();j++)
            {
                if (s[j]!=':')
                {
                    cbL++;
                    currentblocks[cbL]=s[j];
                    
                    if (j==s.length()-1)
                    {
                        bL++;
                        blocks[bL].emptyblockshere=false;
                        for (in=1;in<=4-cbL;in++)
                        {
                            blocks[bL].block[in]='0';
                        }
                        for (in=4-cbL+1;in<=4;in++)
                        {
                            blocks[bL].block[in]=currentblocks[ in-4+cbL ];
                        }
                    }
                }
                else
                {
                    bL++;
                    blocks[bL].emptyblockshere=false;
                    for (in=1;in<=4-cbL;in++)
                    {
                        blocks[bL].block[in]='0';
                    }
                    for (in=4-cbL+1;in<=4;in++)
                    {
                        blocks[bL].block[in]=currentblocks[ in-4+cbL ];
                    }
                    cbL=0;
                }
            }
        }
        else
        {
            for (j=0;j<s.length();j++)
            {
                if (s[j]!=':')
                {
                    cbL++;
                    currentblocks[cbL]=s[j];
                    
                    if (j==s.length()-1)
                    {
                        bL++;
                        blocks[bL].emptyblockshere=false;
                        for (in=1;in<=4-cbL;in++)
                        {
                            blocks[bL].block[in]='0';
                        }
                        for (in=4-cbL+1;in<=4;in++)
                        {
                            blocks[bL].block[in]=currentblocks[ in-4+cbL ];
                        }
                    }
                }
                else
                {
                    bL++;
                    if (cbL==0)
                    {
                        blocks[bL].emptyblockshere=true;
                        continue;
                    }
                    else
                    {
                        blocks[bL].emptyblockshere=false;
                    }
                    for (in=1;in<=4-cbL;in++)
                    {
                        blocks[bL].block[in]='0';
                    }
                    for (in=4-cbL+1;in<=4;in++)
                    {
                        blocks[bL].block[in]=currentblocks[ in-4+cbL ];
                    }
                    cbL=0;
                }
            }
        }
        
        for (in=1;in<=bL;in++)
        {
            if (blocks[in].emptyblockshere)
            {
                for (j=1;j<=8-bL+1;j++)
                {
                    printf("0000");
                    if (j!=8-bL+1)
                    printf(":");
                }
            }
            else
            {
                for (j=1;j<=4;j++)
                printf("%c",blocks[in].block[j]);
            }
            if (in!=bL)
            printf(":");
            else
            printf("\n");
        }
    }
    return 0;
}