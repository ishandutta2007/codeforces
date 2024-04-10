#include<stdio.h>
#include<string.h>

char s[1001];
int z=0, o=1;


int main()
{
    scanf("%s", s);

    int l=strlen(s);

    for(int i=0; i<l; i++)
    {
        if(s[i]=='0')
        {
            printf("%d %d\n", 1, z+1);
            z = (z+1)%4;
        }

        if(s[i]=='1')
        {
            printf("%d %d\n", 3, o);

            o+=2;
            if(o>4) o-=4;
        }
    }
}