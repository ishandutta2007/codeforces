#include <iostream>
#include <stdio.h>
using namespace std;

int n, q;
char str[200111];
bool isabc[200111];

int counter = 0;
void update(int ind)
{
    if (ind < 1 || ind + 2 > n)
        return;

    bool is = str[ind] == 'a' && str[ind+1] == 'b' && str[ind+2] == 'c';

    if (is == isabc[ind])
        return;

    if (is)
        counter++;
    else
        counter--;

    isabc[ind] = is;
}

int main()
{
    int i, j;

    scanf("%d %d", &n, &q);

    scanf("%s", str+1);

    for (i=1;i<=n;i++)
    {
        update(i);
    }

    for (i=1;i<=q;i++)
    {
        int pos;
        char ch[2];

        scanf("%d %s", &pos, ch);
        str[pos] = ch[0];
        update(pos);
        update(pos-1);
        update(pos-2);

        printf("%d\n", counter);
    }
}