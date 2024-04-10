n, m = gets.split.map(&:to_i)
if m == 3 and n >= 5
    puts -1
else
    INF = 100000
    x, y = [], []
    1.upto(m) do |i|
        x << i
        y << INF + i * i
    end
    1.upto(m) do |i|
        x << i
        y << -INF - i * i
    end
    n.times do |i|
        puts "#{x[i]} #{y[i]}"
    end
end