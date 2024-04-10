n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i).sort
if k > n
    puts(-1)
else
    puts(([a[n - k]] * 2).join(' '))
end