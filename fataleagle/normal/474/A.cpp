#include <bits/stdc++.h>

using namespace std;

char shift;
string type;
string keyboard[]={
"qwertyuiop",
"asdfghjkl;",
"zxcvbnm,./"
};

char change(char orig)
{
    int row, pos;
    for(int i=0; i<3; i++)
        if(find(keyboard[i].begin(), keyboard[i].end(), orig)!=keyboard[i].end())
            row=i, pos=find(keyboard[i].begin(), keyboard[i].end(), orig)-keyboard[i].begin();
    if(shift=='L')
        return keyboard[row][pos+1];
    return keyboard[row][pos-1];
}

int main()
{
    cin>>shift>>type;
    for(auto it: type)
        cout<<change(it);
    cout<<endl;
    return 0;
}