#!/usr/bin/ruby

n = gets.chomp.to_i
a = gets.chomp.split

per = 0
a.each { |i| per += i.to_i }
per /= ( n / 2 )


for i in 0...n do
  next if a[i].to_i == 0
  for j in i+1...n do
    if a[j].to_i > 0 && a[i].to_i + a[j].to_i == per
      puts "#{i+1} #{j+1}"
      a[i] = a[j] = "0"
      break
    end
  end
end