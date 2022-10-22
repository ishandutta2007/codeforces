#include<stdio.h>
#include<stack>
#include<string.h>

using namespace std;

stack <int> S;

char s[100001];
int ans;

int main()
{
    scanf("%s", s);

    int l=strlen(s);

    for(int i=0; i<l; i++)
    {
        if(!S.empty() && S.top() == s[i])
        {
            S.pop();
            ans++;
        }
        else S.push(s[i]);
    }

    if(ans&1) printf("Yes");
    else printf("No");
}