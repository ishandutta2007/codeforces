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
        //Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture; // Init

        string[] a = Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        int n = int.Parse(a[0]);
        int m = int.Parse(a[1]);

        int min = (n + 1) / 2, max = n;
        for (int i = min; i <= max; ++i)
        {
            if (i % m == 0)
            {
                Console.Write(i);
                return;
            }
        }
        Console.Write(-1);

        //Console.ReadLine(); // Pause
    }
}