using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;

class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        string[] ta = Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        for (int i = 0; i < n; ++i)
            a[i] = int.Parse(ta[i]);

        Array.Sort(a);
        for (int i = 1; i <= n; ++i)
        {
            bool good = true;
            for (int j = 0; j < n; ++j)
            {
                if (a[j] < j / i)
                {
                    good = false;
                    break;
                }
            }
            if (good)
            {
                Console.WriteLine(i);
                return;
            }
        }
    }
}