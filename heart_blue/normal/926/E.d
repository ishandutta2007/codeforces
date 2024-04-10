import std.stdio;
int[300000] a;
void main()
{
    int n;
    int l = 0, r = 0;
    readf("%d\n",&n);
    a[r++] = -1;
    
    for(int i = 0; i < n; i++)
    {
        int x;
        readf("%d ",&x);
        a[r++] = x;
        while(a[r-2] == a[r-1])
        {
            a[r-2]++;
            r--;
        }
    }
    writeln(r-1);
    for(int i = 1; i < r; i++)
    {
        write(a[i]," ");
    }
}